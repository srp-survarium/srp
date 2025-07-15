void __thiscall boost::system::detail::local_free_on_destruction::~local_free_on_destruction(HLOCAL *this)
{
  LocalFree(*this);
}
