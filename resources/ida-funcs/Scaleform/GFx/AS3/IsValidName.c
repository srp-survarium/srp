Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::IsValidName(
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::AS3::CheckResult *v2; // eax
  unsigned int Length; // ebx
  int v4; // esi
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::AS3::CheckResult v6; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::ASConstString::GetLength(&name->Scaleform::GFx::ASConstString)
    && Scaleform::GFx::AS3::IsNameStartChar(&v6, *name->pNode->pData)->Result )
  {
    Length = Scaleform::GFx::ASConstString::GetLength(&name->Scaleform::GFx::ASConstString);
    v4 = 1;
    if ( Length <= 1 )
    {
LABEL_8:
      v2 = result;
      result->Result = 1;
    }
    else
    {
      pNode = name->pNode;
      while ( Scaleform::GFx::AS3::IsNameChar(&v6, pNode->pData[v4])->Result )
      {
        if ( ++v4 >= Length )
          goto LABEL_8;
      }
      v2 = result;
      result->Result = 0;
    }
  }
  else
  {
    v2 = result;
    result->Result = 0;
  }
  return v2;
}
