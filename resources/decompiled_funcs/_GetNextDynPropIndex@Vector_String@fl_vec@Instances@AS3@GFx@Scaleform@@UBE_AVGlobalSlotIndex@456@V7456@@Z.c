Scaleform::GFx::AS3::GlobalSlotIndex *__thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::GetNextDynPropIndex(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::GlobalSlotIndex *result,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  unsigned int (__thiscall *GetArraySize)(struct Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *); // edx
  unsigned int v4; // esi
  int v5; // eax

  GetArraySize = this->V.GetArraySize;
  result->Index = 0;
  v4 = ind.Index - 1;
  v5 = GetArraySize(&this->V);
  if ( (signed int)(ind.Index - 1) >= 0 )
  {
    if ( v4 < v5 - 1 && (ind.Index & 0x80000000) == 0 )
      result->Index = v4 + 2;
  }
  else if ( v5 )
  {
    result->Index = 1;
    return result;
  }
  return result;
}
