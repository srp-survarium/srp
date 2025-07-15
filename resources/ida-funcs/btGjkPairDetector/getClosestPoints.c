void __thiscall btGjkPairDetector::getClosestPoints(
        btGjkPairDetector *this,
        btDiscreteCollisionDetectorInterface::Result *input,
        btIDebugDraw *output,
        btIDebugDraw *debugDraw,
        bool swapResults)
{
  btGjkPairDetector::getClosestPointsNonVirtual(
    this,
    (const btDiscreteCollisionDetectorInterface::ClosestPointInput *)this,
    input,
    output,
    (int)debugDraw);
}
