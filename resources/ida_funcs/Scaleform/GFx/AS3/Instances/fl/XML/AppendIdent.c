void __cdecl Scaleform::GFx::AS3::Instances::fl::XML::AppendIdent(Scaleform::StringBuffer *buf, int ident)
{
  int i; // edi
  unsigned int v3; // esi

  for ( i = ident; i; i -= v3 )
  {
    v3 = i;
    if ( i >= 10 )
      v3 = 10;
    Scaleform::StringBuffer::AppendString(buf, (char *)offsets[v3], v3);
  }
}
