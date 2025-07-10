double __thiscall btCollisionShape::getContactBreakingThreshold(btCollisionShape *this, float defaultContactThreshold)
{
  return ((double (__thiscall *)(btCollisionShape *))this->getAngularMotionDisc)(this) * defaultContactThreshold;
}
