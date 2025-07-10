BOOL __cdecl Scaleform::GFx::AS3::IsScaleformGFx(const Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  unsigned int Size; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx

  if ( (_S14 & 1) != 0 )
  {
    Size = scaleform_gfx.Size;
  }
  else
  {
    _S14 |= 1u;
    Size = 13;
    scaleform_gfx.pStr = "scaleform.gfx";
    scaleform_gfx.Size = 13;
  }
  pNode = ns->Uri.pNode;
  return pNode->Size >= Size && !strncmp(pNode->pData, scaleform_gfx.pStr, Size);
}
