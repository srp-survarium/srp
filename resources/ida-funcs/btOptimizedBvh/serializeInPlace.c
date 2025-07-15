// attributes: thunk
bool __thiscall btOptimizedBvh::serializeInPlace(
        btOptimizedBvh *this,
        void *o_alignedDataBuffer,
        unsigned int i_dataBufferSize,
        bool i_swapEndian)
{
  return btQuantizedBvh::serialize(this, o_alignedDataBuffer, i_dataBufferSize, i_swapEndian);
}
