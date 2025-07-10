void __thiscall Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::keyLocationGet(
        Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *this,
        unsigned int *result)
{
  unsigned __int8 States; // al
  int KeyLocation; // eax

  if ( this->KeyLocation >= 0 )
  {
    *result = this->KeyLocation;
  }
  else
  {
    States = this->EvtId.KeysState.States;
    if ( (States & 7) != 0 )
    {
      KeyLocation = ((States & 0x40) != 0) + 1;
      this->KeyLocation = KeyLocation;
    }
    else
    {
      this->KeyLocation = 0;
      KeyLocation = this->KeyLocation;
    }
    *result = KeyLocation;
  }
}
