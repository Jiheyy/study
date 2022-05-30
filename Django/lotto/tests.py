from django.test import TestCase

# Create your tests here.
from .models import GuessNumber

class GuessNumberTestCase(TestCase):
    def test_generate(self):
        g = GuessNumber(name='apple', text='pineapple')
        g.generate()
        print(g.update_date)
        print(g.lottos)
        self.assertTrue(len(g.lottos) <= 25)
