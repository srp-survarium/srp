Scaleform::GFx::DisplayObjectBase::TopMostResult __thiscall Scaleform::GFx::Button::GetTopMostMouseEntity(
        Scaleform::GFx::Button *this,
        const Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::DisplayObjectBase::TopMostDescr *v3; // edi
  Scaleform::GFx::DisplayObjectBase::TopMostResult result; // eax
  int v6; // ebx
  Scaleform::GFx::DisplayObjectBase *pObject; // edi
  Scaleform::Render::Point<float> p; // [esp+10h] [ebp-10h] BYREF
  Scaleform::Render::Point<float> subp; // [esp+18h] [ebp-8h] BYREF

  v3 = pdescr;
  pdescr->pResult = 0;
  if ( !this->GetVisible(this)
    || pdescr->pIgnoreMC == this
    || !this->IsFocusAllowed(this, this->pASRoot->pMovieImpl, pdescr->ControllerIdx)
    || !Scaleform::GFx::DisplayObject::TransformPointToLocalAndCheckBounds(this, &p, pt, 1, 0) )
  {
    return 2;
  }
  v6 = 0;
  if ( this->States[3].Characters.Data.Size )
  {
    while ( 1 )
    {
      pObject = this->States[3].Characters.Data.Data[v6].Char.pObject;
      if ( pObject )
      {
        Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(pObject, &subp, &p, 1, 0);
        if ( pObject->PointTestLocal(pObject, &subp, 1u) )
          break;
      }
      if ( ++v6 >= this->States[3].Characters.Data.Size )
      {
        v3 = pdescr;
        goto LABEL_11;
      }
    }
    pdescr->pResult = this;
    return 1;
  }
  else
  {
LABEL_11:
    result = TopMost_Continue;
    v3->LocalPt = p;
  }
  return result;
}
