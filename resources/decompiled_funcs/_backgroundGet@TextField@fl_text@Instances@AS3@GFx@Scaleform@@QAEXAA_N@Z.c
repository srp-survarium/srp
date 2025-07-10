void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::backgroundGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        bool *result)
{
  *result = HIBYTE(this->pDispObj.pObject[1].pRenNode.pObject[8].PNode.pVoidNext) != 0;
}
