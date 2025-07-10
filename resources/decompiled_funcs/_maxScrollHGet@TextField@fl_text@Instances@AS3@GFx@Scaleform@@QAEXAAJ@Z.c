void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::maxScrollHGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result)
{
  *result = (int)((double)Scaleform::Render::Text::DocView::GetMaxHScroll((Scaleform::Render::Text::DocView *)this->pDispObj.pObject[1].pRenNode.pObject)
                * 0.05);
}
