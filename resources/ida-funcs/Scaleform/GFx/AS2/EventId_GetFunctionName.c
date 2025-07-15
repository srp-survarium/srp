Scaleform::GFx::ASString *__cdecl Scaleform::GFx::AS2::EventId_GetFunctionName(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::StringManager *psm,
        const Scaleform::GFx::EventId *evt)
{
  unsigned int v3; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASString *v5; // eax

  if ( evt->Id > 0x800000 )
    v3 = evt->Id - 16777191;
  else
    v3 = (unsigned __int8)Scaleform::Alg::BitCount32(evt->Id);
  if ( v3 - 1 > 0x21 )
    pNode = psm->Builtins[46].pNode;
  else
    pNode = psm->Builtins[dword_6F9848[v3]].pNode;
  v5 = result;
  ++pNode->RefCount;
  result->pNode = pNode;
  return v5;
}
