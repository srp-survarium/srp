void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::typeSet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::Render::BevelFilter *v3; // eax
  Scaleform::Render::BevelFilter *v4; // eax
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  if ( !strcmp(value->pNode->pData, "inner") )
  {
    v3 = this->GetBevelFilterData(this);
    v3->Params.Mode |= 0x20u;
  }
  else if ( !strcmp(value->pNode->pData, "outer") )
  {
    v4 = this->GetBevelFilterData(this);
    v4->Params.Mode &= ~0x20u;
  }
  else if ( !strcmp(value->pNode->pData, "full") )
  {
    UI = this->pTraits.pObject->pVM->UI;
    UI->Output(UI, Output_Warning, "The method instance::BevelFilter::typeSet() - full is not implemented\n");
  }
}
