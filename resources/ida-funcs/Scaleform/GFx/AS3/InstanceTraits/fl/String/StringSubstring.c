Scaleform::GFx::ASString *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSubstring(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::StringManager *sm,
        const Scaleform::GFx::ASString *self,
        char *start,
        int length)
{
  int v5; // edi
  Scaleform::GFx::ASStringManager *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // ecx
  Scaleform::GFx::ASString *v8; // eax
  char *v9; // esi
  signed int v10; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // ecx
  Scaleform::GFx::ASStringNode *v13; // eax

  v5 = length;
  if ( length )
  {
    v9 = start;
    if ( (int)start < 0 )
      v9 = 0;
    v10 = Scaleform::GFx::ASConstString::GetLength(&self->Scaleform::GFx::ASConstString);
    if ( (int)v9 < v10 )
    {
      if ( length < 0 || (int)&v9[length] > v10 )
        v5 = v10 - (_DWORD)v9;
      v13 = Scaleform::GFx::ASConstString::SubstringNode(&self->Scaleform::GFx::ASConstString, v9, &v9[v5]);
      ++v13->RefCount;
      result->pNode = v13;
      return result;
    }
    else
    {
      pStringManager = sm->pStringManager;
      ++pStringManager->EmptyStringNode.RefCount;
      p_EmptyStringNode = &pStringManager->EmptyStringNode;
      v8 = result;
      result->pNode = p_EmptyStringNode;
    }
  }
  else
  {
    v6 = sm->pStringManager;
    ++v6->EmptyStringNode.RefCount;
    v7 = &v6->EmptyStringNode;
    v8 = result;
    result->pNode = v7;
  }
  return v8;
}
