void __thiscall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::customItemsGet(
        Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *Array; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // esi
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::FlashUI *UI; // ecx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v8; // [esp+Ch] [ebp-4h] BYREF

  Array = Scaleform::GFx::AS3::VM::MakeArray(this->pTraits.pObject->pVM, &v8);
  pV = Array->pV;
  pObject = result->pObject;
  if ( Array->pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = pV;
  }
  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method instance::ContextMenu::customItemsGet() is not implemented\n");
}
