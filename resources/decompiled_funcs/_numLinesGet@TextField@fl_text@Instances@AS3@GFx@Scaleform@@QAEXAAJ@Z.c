void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::numLinesGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result)
{
  *result = Scaleform::Render::Text::DocView::GetLinesCount((Scaleform::Render::Text::DocView *)this->pDispObj.pObject[1].pRenNode.pObject);
}
