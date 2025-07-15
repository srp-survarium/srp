void __usercall boost::weak_ptr<void>::~weak_ptr<void>(boost::weak_ptr<void> *this@<ecx>, int a2@<eax>)
{
  volatile signed __int32 *v2; // ecx

  v2 = *(volatile signed __int32 **)(a2 + 4);
  if ( v2 )
  {
    if ( !_InterlockedExchangeAdd(v2 + 2, 0xFFFFFFFF) )
      (*(void (__thiscall **)(volatile signed __int32 *))(*v2 + 8))(v2);
  }
}
