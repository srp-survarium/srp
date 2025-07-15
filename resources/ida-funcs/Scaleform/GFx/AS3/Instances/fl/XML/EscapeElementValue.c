void __cdecl Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(
        Scaleform::StringBuffer *buf,
        const Scaleform::GFx::ASString *v)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::ASString *v3; // edi
  unsigned int Char_Advance0; // eax

  pNode = v->pNode;
  v = (const Scaleform::GFx::ASString *)v->pNode->pData;
  v3 = (const Scaleform::GFx::ASString *)((char *)v + pNode->Size);
  while ( v < v3 )
  {
    Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v);
    switch ( Char_Advance0 )
    {
      case '"':
        Scaleform::StringBuffer::AppendString(buf, (const __m128i *)aQuo, 6u);
        break;
      case '&':
        Scaleform::StringBuffer::AppendString(buf, (const __m128i *)aAmp_3, 5u);
        break;
      case '\'':
        Scaleform::StringBuffer::AppendString(buf, (const __m128i *)aApo, 6u);
        break;
      case '<':
        Scaleform::StringBuffer::AppendString(buf, (const __m128i *)"&lt;", 4u);
        break;
      case '>':
        Scaleform::StringBuffer::AppendString(buf, (const __m128i *)"&gt;", 4u);
        break;
      default:
        Scaleform::StringBuffer::AppendChar(buf, Char_Advance0);
        break;
    }
  }
}
