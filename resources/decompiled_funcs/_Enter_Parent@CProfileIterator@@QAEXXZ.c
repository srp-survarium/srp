void __usercall CProfileIterator::Enter_Parent(CProfileIterator *this@<ecx>, _DWORD *a2@<eax>)
{
  int v2; // ecx

  v2 = *(_DWORD *)(*a2 + 20);
  if ( v2 )
    *a2 = v2;
  a2[1] = *(_DWORD *)(*a2 + 24);
}
