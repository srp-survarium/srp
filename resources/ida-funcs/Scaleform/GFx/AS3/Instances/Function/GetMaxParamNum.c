unsigned int __thiscall Scaleform::GFx::AS3::Instances::Function::GetMaxParamNum(
        Scaleform::GFx::AS3::Instances::Function *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax

  pObject = this->pTraits.pObject;
  return *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(pObject[1].Parent[2].VArray.Data.Size + 120)
                               + 4
                               * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(pObject[1].Parent[2].VArray.Data.Size + 180)
                                                       + 4
                                                       * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(pObject[1].Parent[2].VArray.Data.Size
                                                                                           + 120)
                                                                               + 4 * pObject[1].FirstOwnSlotNum)
                                                                   + 8))
                                           + 12))
                   + 16);
}
