vostok::math::quaternion *__usercall vostok::math::slerp@<eax>(
        const vostok::math::quaternion *q0@<ecx>,
        const vostok::math::quaternion *q1@<eax>,
        _QWORD *t,
        float ta)
{
  slerp_optimized(q0, q1, t, ta);
  return (vostok::math::quaternion *)t;
}
