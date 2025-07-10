vostok::animation::frame *__userpurge vostok::animation::bone_animation::bone_frame@<eax>(
        vostok::animation::bone_animation *this@<ecx>,
        vostok::animation::current_frame_position *frame_position@<eax>,
        vostok::animation::frame *a3@<esi>,
        float a4@<xmm4>,
        float time)
{
  vostok::animation::evaluate_frame(this->m_channels, a3, a4, time, frame_position);
  return a3;
}
