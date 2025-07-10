void __thiscall boost::detail::sp_counted_base::destroy(boost::detail::sp_counted_base *this)
{
  if ( this )
    ((void (__thiscall *)(boost::detail::sp_counted_base *, int))this->~boost::detail::sp_counted_base)(this, 1);
}
