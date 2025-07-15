void __usercall Wm4::HullEdge2<float>::DeleteAll(Wm4::HullEdge2<float> *this@<ecx>, _DWORD *a2@<edi>)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi

  v2 = (_DWORD *)a2[3];
  if ( v2 )
  {
    do
    {
      if ( v2 == a2 )
        break;
      v3 = (_DWORD *)v2[3];
      operator delete(v2);
      v2 = v3;
    }
    while ( v3 );
  }
  operator delete(a2);
}
