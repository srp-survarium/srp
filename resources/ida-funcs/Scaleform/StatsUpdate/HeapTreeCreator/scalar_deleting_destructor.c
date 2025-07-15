Scaleform::StatsUpdate::HeapTreeCreator *__thiscall Scaleform::StatsUpdate::HeapTreeCreator::`scalar deleting destructor'(
        Scaleform::StatsUpdate::HeapTreeCreator *this,
        char a2)
{
  Scaleform::StatsUpdate::HeapTreeCreator::~HeapTreeCreator(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
