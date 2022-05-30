from django.shortcuts import render, redirect
from django.http import HttpResponse
from .models import GuessNumber

def index(request):
    lottos = GuessNumber.objects.all()
    return render(request, "lotto/default.html", {"lottos": lottos})

def post(request):
    if request.methos == "POST":
        form = PostForm(request.POST)
        if form.is_valid():
            lotto = form.save(commit = False)
            lotto.generate() 
            return redirect('index')
    else: # to register page
        form = PostForm()
        return render(request, 'lotto/form.html', {"form": form})

def detail(request, lottokey):
    lotto = GuessNumber.objects.get(pk= lottokey)
    return render(request, 'lotto/detail.html', {"lotto": lotto})

