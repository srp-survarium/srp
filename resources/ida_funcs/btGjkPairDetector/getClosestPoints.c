void __thiscall btGjkPairDetector::getClosestPoints(
        btGjkPairDetector *this,
        const btDiscreteCollisionDetectorInterface::ClosestPointInput *input,
        btDiscreteCollisionDetectorInterface::Result *output,
        btIDebugDraw *debugDraw,
        bool swapResults)
{
  btGjkPairDetector::getClosestPointsNonVirtual(this, this, input, output, debugDraw);
}
