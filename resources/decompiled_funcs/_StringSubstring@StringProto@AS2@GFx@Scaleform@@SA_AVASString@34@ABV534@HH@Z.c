Scaleform::GFx::ASString *__cdecl Scaleform::GFx::AS2::StringProto::StringSubstring(
        Scaleform::GFx::ASString *result,
        const Scaleform::GFx::ASString *self,
        const char *start,
        int length)
{
  int v4; // edi
  Scaleform::GFx::ASStringManager *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // ecx
  Scaleform::GFx::ASString *v7; // eax
  const char *v8; // esi
  signed int v9; // eax
  Scaleform::GFx::ASStringManager *pManager; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // ecx
  Scaleform::GFx::ASStringNode *v12; // eax

  v4 = length;
  if ( length )
  {
    v8 = start;
    if ( (int)start < 0 )
      v8 = 0;
    v9 = Scaleform::GFx::ASConstString::GetLength(&self->Scaleform::GFx::ASConstString);
    if ( (int)v8 < v9 )
    {
      if ( length < 0 || (int)&v8[length] > v9 )
        v4 = v9 - (_DWORD)v8;
      v12 = Scaleform::GFx::ASConstString::SubstringNode(&self->Scaleform::GFx::ASConstString, v8, &v8[v4]);
      ++v12->RefCount;
      result->pNode = v12;
      return result;
    }
    else
    {
      pManager = self->pNode->pManager;
      ++pManager->EmptyStringNode.RefCount;
      p_EmptyStringNode = &pManager->EmptyStringNode;
      v7 = result;
      result->pNode = p_EmptyStringNode;
    }
  }
  else
  {
    v5 = self->pNode->pManager;
    ++v5->EmptyStringNode.RefCount;
    v6 = &v5->EmptyStringNode;
    v7 = result;
    result->pNode = v6;
  }
  return v7;
}
