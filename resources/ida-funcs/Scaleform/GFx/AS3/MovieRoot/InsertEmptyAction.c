Scaleform::GFx::AS3::MovieRoot::ActionEntry *__thiscall Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::MovieRoot::ActionLevel lvl)
{
  return Scaleform::GFx::AS3::MovieRoot::ActionQueueType::InsertEntry(&this->ActionQueue, lvl);
}
