void __cdecl Scaleform::Render::ConvertIndices(
        __m128i *pdest,
        __m128i *psource,
        unsigned int count,
        unsigned __int16 delta)
{
  if ( Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics() )
    Scaleform::Render::ConvertIndices_SIMD(pdest, psource, count, delta);
  else
    Scaleform::Render::ConvertIndices_NonOpt((unsigned __int16 *)pdest, (unsigned __int16 *)psource, count, delta);
}
