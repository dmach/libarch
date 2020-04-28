libarch
=======

* Libarch is a library for detecting architectures for package managers and managing relations among them.
* It was originally written for [libdnf](https://github.com/rpm-software-management/libdnf).


Documentation
=============

* For HTML documentation see https://libarch.readthedocs.io/
* The header files are documented because documentation is mainly generated from them


Reporting issues
================

* [Red Hat Bugzilla](https://bugzilla.redhat.com/enter_bug.cgi?product=Fedora&component=libarch) is the preferred way of filing issues. [[backlog](https://bugzilla.redhat.com/buglist.cgi?bug_status=__open__&product=Fedora&component=libarch)]
* [GitHub issues](https://github.com/rpm-software-management/libarch/issues/new) are also accepted. [[backlog](https://github.com/rpm-software-management/libarch/issues)]


Contributing
============

* By contributing to this project you agree to the Developer Certificate of Origin (DCO).
  This document is a simple statement that you, as a contributor,
  have the legal right to submit the contribution. See the [DCO](DCO) file for details.
* All contributions to this project are licensed under [MIT](mit.txt).
  See the [License](#license) section for details.


Writing patches
---------------

* Please follow the [coding style](CODING_STYLE.md)
* When a patch is ready, submit a pull request
* It is a good practice to write documentation and unit tests as part of the patches


Building
--------
To install build requirements, run::

    $ dnf builddep libarch.spec --define '_with_sanitizers 1' [--define '_without_<option> 1 ...]

To build code, run::

    $ mkdir build
    $ cd build
    $ cmake .. -DWITH_SANITIZERS=ON [-DWITH_<OPTION>=<ON|OFF> ...]
    $ make -j4

To build rpms from git, run::

    $ export PREFIX=$(rpmspec libarch.spec -q --srpm --qf '%{name}-%{version}'); git archive --format=tar.gz --prefix=$PREFIX/ HEAD > $PREFIX.tar.gz
    $ rpmbuild -ba --define "_sourcedir $(pwd)" libarch.spec [--with=<option>|--without=<option> ...]


Testing
-------
To run the tests, follow the steps to build the code and then run::

    # from the 'build' directory
    $ CTEST_OUTPUT_ON_FAILURE=1 make test

As an alternative, tests can be executed in a verbose mode::

    # from the 'build' directory
    $ make test ARGS='-V'


License
=======

* The project is licensed under [MIT](mit.txt)
* See [COPYING](COPYING.md) for more details
