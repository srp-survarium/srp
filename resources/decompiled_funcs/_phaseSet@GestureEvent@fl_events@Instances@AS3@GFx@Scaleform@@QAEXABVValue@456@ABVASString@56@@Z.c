void __thiscall Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::phaseSet(
        Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  const char *pData; // esi

  pNode = value->pNode;
  if ( value->pNode == &value->pNode->pManager->NullStringNode )
  {
    this->Phase = Phase_All;
  }
  else
  {
    pData = pNode->pData;
    if ( !strcmp(pNode->pData, "all") )
    {
      this->Phase = Phase_Begin;
    }
    else if ( !strcmp(pData, "begin") )
    {
      this->Phase = Phase_End;
    }
    else if ( Scaleform::GFx::ASString::operator==(value, "end") )
    {
      this->Phase = Phase_Update;
    }
    else
    {
      this->Phase = Scaleform::GFx::ASString::operator==(value, "update") ? 4 : Phase_All;
    }
  }
}
