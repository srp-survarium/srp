void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::scrollVGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result)
{
  *result = Scaleform::Render::Text::DocView::GetVScrollOffset((Scaleform::Render::Text::DocView *)this->pDispObj.pObject[1].pRenNode.pObject)
          + 1;
}
