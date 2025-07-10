void __thiscall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::builtInItemsGet(
        Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems> *result)
{
  Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  pObject = result->pObject;
  if ( result->pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      result->pObject = (Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    result->pObject = 0;
  }
  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method instance::ContextMenu::builtInItemsGet() is not implemented\n");
}
