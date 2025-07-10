void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::maxCharsGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  int pRenderer; // eax

  pObject = this->pDispObj.pObject;
  *result = 0;
  pRenderer = (int)pObject[1].pRenNode.pObject[5].pRenderer;
  if ( pRenderer )
    *result = pRenderer;
}
