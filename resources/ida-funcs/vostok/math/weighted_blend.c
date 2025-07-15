const stlp_std::pair<vostok::math::quaternion,float> *__usercall vostok::math::weighted_blend@<eax>(
        const stlp_std::pair<vostok::math::quaternion,float> *end@<eax>,
        const stlp_std::pair<vostok::math::quaternion,float> *a2@<esi>,
        const stlp_std::pair<vostok::math::quaternion,float> *begin)
{
  extrapolated_slerp(begin, a2, end);
  return a2;
}
