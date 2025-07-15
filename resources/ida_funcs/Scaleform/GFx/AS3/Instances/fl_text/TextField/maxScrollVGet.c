void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::maxScrollVGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result)
{
  *result = Scaleform::Render::Text::DocView::GetMaxVScroll((Scaleform::Render::Text::DocView *)this->pDispObj.pObject[1].pRenNode.pObject)
          + 1;
}
