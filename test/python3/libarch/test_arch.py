import unittest

import libarch.arch


class TestArch(unittest.TestCase):
    def test_x86_64_name(self):
        arch = libarch.arch.get_arch("x86_64")
        self.assertEqual(libarch.arch.get_arch_name(arch), "x86_64")

    def test_x86_64_bits(self):
        arch = libarch.arch.get_arch("x86_64")
        self.assertEqual(libarch.arch.get_arch_bits(arch), 64)

    def test_x86_64_is_multilib(self):
        arch = libarch.arch.get_arch("x86_64")
        self.assertEqual(libarch.arch.get_arch_is_multilib(arch), True)

    def test_x86_64_is_source(self):
        arch = libarch.arch.get_arch("x86_64")
        self.assertEqual(libarch.arch.get_arch_is_source(arch), False)

    def test_x86_64_is_noarch(self):
        arch = libarch.arch.get_arch("x86_64")
        self.assertEqual(libarch.arch.get_arch_is_noarch(arch), False)

    def test_x86_64_compatible_native_arches(self):
        arch = libarch.arch.get_arch("x86_64")
        actual = libarch.arch.get_arch_compatible_native_arches(arch)
        expected = ("x86_64", "noarch")
        self.assertEqual(expected, actual)

    def test_x86_64_compatible_multilib_arches(self):
        arch = libarch.arch.get_arch("x86_64")
        actual = libarch.arch.get_arch_compatible_multilib_arches(arch)
        expected = ("athlon", "i686", "i586", "i486", "i386")
        self.assertEqual(expected, actual)
