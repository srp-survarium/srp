int __thiscall Scaleform::GFx::StaticTextCharacter::GetTopMostMouseEntity(
        Scaleform::GFx::StaticTextCharacter *this,
        const Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::InteractiveObject *TopMostMouseEntityDef; // eax

  TopMostMouseEntityDef = Scaleform::GFx::DisplayObjectBase::GetTopMostMouseEntityDef(
                            this,
                            this->pDef.pObject,
                            pt,
                            pdescr->TestAll,
                            pdescr->pIgnoreMC);
  pdescr->pResult = TopMostMouseEntityDef;
  return 2 - (TopMostMouseEntityDef != 0);
}
