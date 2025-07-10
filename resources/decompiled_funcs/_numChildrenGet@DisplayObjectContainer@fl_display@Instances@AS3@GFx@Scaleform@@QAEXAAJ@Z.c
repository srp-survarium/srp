void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::numChildrenGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        int *result)
{
  *result = (int)this->pDispObj.pObject[1].pRenNode.pObject;
}
