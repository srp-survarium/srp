void __thiscall Scaleform::GFx::AS2::ArrayObject::JoinToString(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::Environment *pEnv,
        Scaleform::StringBuffer *pbuffer,
        const __m128i *pDelimiter)
{
  Scaleform::StringBuffer *v4; // edi
  Scaleform::GFx::AS2::ArrayObject *v5; // esi
  int v6; // ebx
  Scaleform::GFx::AS2::Environment *v7; // ebp
  Scaleform::GFx::AS2::Value **v8; // eax
  Scaleform::GFx::ASStringNode *v9; // esi
  Scaleform::GFx::AS2::Value v12; // [esp+10h] [ebp-10h] BYREF

  v4 = pbuffer;
  v5 = this;
  Scaleform::StringBuffer::Clear(pbuffer);
  v6 = 0;
  v12.T.Type = 0;
  if ( v5->Elements.Data.Size )
  {
    v7 = pEnv;
    while ( 1 )
    {
      if ( v6 )
        Scaleform::StringBuffer::AppendString(v4, pDelimiter, 0xFFFFFFFF);
      v8 = &v5->Elements.Data.Data[v6];
      if ( *v8 )
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(*v8, (Scaleform::GFx::ASString *)&pbuffer, v7, -1, 0);
        v9 = (Scaleform::GFx::ASStringNode *)pbuffer;
        Scaleform::StringBuffer::AppendString(v4, (const __m128i *)pbuffer->pData, 0xFFFFFFFF);
      }
      else
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(&v12, (Scaleform::GFx::ASString *)&pEnv, v7, -1, 0);
        v9 = (Scaleform::GFx::ASStringNode *)pEnv;
        Scaleform::StringBuffer::AppendString(v4, (const __m128i *)pEnv->__vftable, 0xFFFFFFFF);
      }
      if ( v9->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      if ( ++v6 >= this->Elements.Data.Size )
        break;
      v5 = this;
    }
  }
}
