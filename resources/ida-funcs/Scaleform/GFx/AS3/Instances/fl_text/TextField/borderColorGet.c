void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::borderColorGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        unsigned int *result)
{
  *result = (int)this->pDispObj.pObject[1].pRenNode.pObject[8].PNode.Scaleform::Render::ContextImpl::Entry::pPrev
          & 0xFFFFFF;
}
