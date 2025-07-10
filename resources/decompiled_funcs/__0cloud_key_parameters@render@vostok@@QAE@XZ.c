void __thiscall vostok::render::cloud_key_parameters::cloud_key_parameters(vostok::render::cloud_key_parameters *this)
{
  const vostok::math::float4x4 *v1; // xmm0_4

  this->cloud_base = 3200.0;
  this->layer_height = 7.0;
  v1 = clear_value;
  this->linear_time = 0.0;
  LODWORD(this->direct_light) = v1;
  LODWORD(this->indirect_light) = v1;
  LODWORD(this->ambient) = v1;
  LODWORD(this->extinction) = v1;
  LODWORD(this->detail_noise_wave_lenght) = v1;
  LODWORD(this->detail_noise_amplitude) = v1;
  LODWORD(this->wind_speed) = v1;
  this->cloud_generate_cloudiness = FLOAT_0_5;
  LODWORD(this->cloud_generate_octaves) = v1;
  this->diffusivity = 0.0;
  LODWORD(this->persistence) = v1;
  *(_QWORD *)&this->interp_alpha = 0;
  this->target_key_index = 1;
}
