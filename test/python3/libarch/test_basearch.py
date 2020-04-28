import unittest

import libarch.basearch


class TestBaseArch(unittest.TestCase):
    def test_x86_64_compatible_native_arches(self):
        basearch = "x86_64"
        actual = libarch.basearch.get_basearch_compatible_native_arches(basearch)
        expected = ("amd64", "x86_64", "noarch", "ia32e")
        self.assertEqual(expected, actual)

    def test_x86_64_compatible_multilib_arches(self):
        basearch = "x86_64"
        actual = libarch.basearch.get_basearch_compatible_multilib_arches(basearch)
        expected = ("athlon", "i686", "i586", "i486", "i386")
        self.assertEqual(expected, actual)


