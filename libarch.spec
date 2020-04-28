Name:           libarch
Version:        1.0.0
Release:        1%{?dist}
Summary:        Architecture detection and management library
License:        MIT
URL:            https://github.com/rpm-software-management/libarch
Source0:        %{url}/archive/%{version}/%{name}-%{version}.tar.gz


# ========== build options ==========

%bcond_with    html
%bcond_with    man

%bcond_without go
%bcond_without perl5
%bcond_without python3
%bcond_without ruby

%bcond_with    sanitizers
%bcond_without tests


# ========== versions of dependencies ==========

%global swig_version 3.0.12


# ========== build requires ==========

BuildRequires:  cmake
BuildRequires:  doxygen
BuildRequires:  gcc

%if %{with html} || %{with man}
BuildRequires:  python3dist(breathe)
BuildRequires:  python3dist(sphinx)
BuildRequires:  python3dist(sphinx-rtd-theme)
%endif

%if %{with sanitizers}
BuildRequires:  libasan-static
BuildRequires:  liblsan-static
BuildRequires:  libubsan-static
%endif


# ========== libarch ==========

%description
Architecture detection and management library

%files
%{_libdir}/libarch.so.*
%license mit.txt


# ========== libarch-devel ==========

%package devel
Summary:        Development files for libarch
Requires:       libarch%{?_isa} = %{version}-%{release}

%description devel
Development files for libarch.

%files devel
%{_includedir}/libarch/
%{_libdir}/libarch.so
%{_libdir}/pkgconfig/libarch.pc
%license COPYING.md
%license mit.txt


# ========== perl5-libarch ==========

%if %{with perl5}
%package -n perl5-libarch
Summary:        Perl 5 for the libarch library.
Provides:       perl(libarch) = %{version}-%{release}
Requires:       libarch%{?_isa} = %{version}-%{release}
BuildRequires:  perl-devel
BuildRequires:  swig >= %{swig_version}
%if %{with tests}
BuildRequires:  perl(strict)
BuildRequires:  perl(Test::More)
BuildRequires:  perl(warnings)
%endif

%description -n perl5-libarch
Perl 5 bindings for the libarch library.

%files -n perl5-libarch
%{perl_vendorarch}/libarch
%{perl_vendorarch}/auto/libarch
%license COPYING.md
%license mit.txt
%endif


# ========== python3-libarch ==========

%if %{with python3}
%package -n python3-libarch
%{?python_provide:%python_provide python3-libarch}
Summary:        Python 3 bindings for the libarch library.
Requires:       libarch%{?_isa} = %{version}-%{release}
BuildRequires:  python3-devel
BuildRequires:  swig >= %{swig_version}

%description -n python3-libarch
Python 3 bindings for the libarch library.

%files -n python3-libarch
%{python3_sitearch}/libarch/
%license COPYING.md
%license mit.txt
%endif


# ========== ruby-libarch ==========

%if %{with ruby}
%package -n ruby-libarch
Summary:        Ruby bindings for the libarch library.
Provides:       ruby(libarch) = %{version}-%{release}
Requires:       libarch%{?_isa} = %{version}-%{release}
Requires:       ruby(release)
BuildRequires:  pkgconfig(ruby)
BuildRequires:  swig >= %{swig_version}

%description -n ruby-libarch
Ruby bindings for the libarch library.

%files -n ruby-libarch
%{ruby_vendorarchdir}/libarch/
%license COPYING.md
%license mit.txt
%endif


# ========== unpack, build, check & install ==========

%prep
%autosetup -p1


%build
%cmake \
    -DPACKAGE_VERSION=%{version} \
    -DPERL_INSTALLDIRS=vendor \
    \
    -DWITH_HTML=%{?with_html:ON}%{!?with_html:OFF} \
    -DWITH_MAN=%{?with_man:ON}%{!?with_man:OFF} \
    \
    -DWITH_GO=%{?with_go:ON}%{!?with_go:OFF} \
    -DWITH_PERL5=%{?with_perl5:ON}%{!?with_perl5:OFF} \
    -DWITH_PYTHON3=%{?with_python3:ON}%{!?with_python3:OFF} \
    -DWITH_RUBY=%{?with_ruby:ON}%{!?with_ruby:OFF} \
    \
    -DWITH_SANITIZERS=%{?with_sanitizers:ON}%{!?with_sanitizers:OFF} \
    -DWITH_TESTS=%{?with_tests:ON}%{!?with_tests:OFF}
%make_build
%if %{with man}
    make doc-man
%endif


%check
%if %{with tests}
    make ARGS="-V" test
%endif


%install
%make_install


%ldconfig_scriptlets


%changelog
