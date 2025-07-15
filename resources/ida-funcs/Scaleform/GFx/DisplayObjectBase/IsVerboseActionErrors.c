BOOL __thiscall Scaleform::GFx::DisplayObjectBase::IsVerboseActionErrors(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType **p_pIndXFormData; // eax

  p_pIndXFormData = &this[-1].pIndXFormData;
  if ( this == (Scaleform::GFx::DisplayObjectBase *)12 )
    return (MEMORY[0x3F74] & 0x40) == 0;
  while ( *((char *)p_pIndXFormData + 62) >= 0 )
  {
    p_pIndXFormData = (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType **)p_pIndXFormData[8];
    if ( !p_pIndXFormData )
      return (MEMORY[0x3F74] & 0x40) == 0;
  }
  return (*(_DWORD *)(LODWORD(p_pIndXFormData[4]->OrigTransformMatrix.M[0][2]) + 16244) & 0x40) == 0;
}
