void __usercall boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        boost::function<void __cdecl(void)> *this@<ecx>,
        void (__cdecl *f)()@<eax>)
{
  int v2; // [esp+0h] [ebp-4h]

  boost::function0<void>::function0<void>(this, f, v2);
}
