void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::maxCharsSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::Render::TreeCacheNode *value)
{
  if ( (int)value >= 0 )
    this->pDispObj.pObject[1].pRenNode.pObject[5].pRenderer = value;
}
