Scaleform::GFx::DisplayObjectBase::TopMostResult __userpurge Scaleform::GFx::AS3::ShapeObject::GetTopMostMouseEntity@<eax>(
        Scaleform::GFx::AS3::ShapeObject *this@<ecx>,
        int a2@<ebx>,
        const Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::DisplayObjectBase::TopMostResult result; // eax
  Scaleform::GFx::InteractiveObject *TopMostMouseEntityDef; // eax
  bool v7; // zf
  Scaleform::Render::Point<float> p; // [esp+4h] [ebp-8h] BYREF

  if ( this->pDrawing.pObject )
  {
    if ( Scaleform::GFx::DisplayObject::TransformPointToLocalAndCheckBounds(this, &p, pt, 1, 0)
      && Scaleform::GFx::DrawingContext::DefPointTestLocal(this->pDrawing.pObject, a2, &p, 1, this) )
    {
      pdescr->pResult = this->pParent;
      return 1;
    }
  }
  else
  {
    TopMostMouseEntityDef = Scaleform::GFx::DisplayObjectBase::GetTopMostMouseEntityDef(
                              this,
                              this->pDef.pObject,
                              pt,
                              pdescr->TestAll,
                              pdescr->pIgnoreMC);
    pdescr->pResult = TopMostMouseEntityDef;
    v7 = TopMostMouseEntityDef == 0;
    result = TopMost_Continue;
    if ( !v7 )
      return result;
  }
  return 2;
}
