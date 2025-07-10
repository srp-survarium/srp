void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::Button::CharToRec>::DestructArray(
        Scaleform::GFx::Button::CharToRec *p,
        unsigned int count)
{
  Scaleform::GFx::Button::CharToRec *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->Char.pObject )
        Scaleform::RefCountNTSImpl::Release(v2->Char.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
