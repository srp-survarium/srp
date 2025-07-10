void __thiscall boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        boost::function<void __cdecl(void)> *this,
        const boost::function<void __cdecl(void)> *f)
{
  this->vtable = 0;
  boost::function0<void>::assign_to_own(this, f);
}
