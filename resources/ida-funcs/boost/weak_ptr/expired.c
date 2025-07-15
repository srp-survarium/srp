bool __usercall boost::weak_ptr<void>::expired@<al>(boost::weak_ptr<void> *this@<ecx>, int a2@<eax>)
{
  int v2; // eax
  int v3; // eax

  v2 = *(_DWORD *)(a2 + 4);
  if ( v2 )
    v3 = *(_DWORD *)(v2 + 4);
  else
    v3 = 0;
  return v3 == 0;
}
