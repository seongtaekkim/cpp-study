#pragma once

/*
 * header에 const를 정의/초기화하여 외부 cpp파일에서 사용하면
 * 변수를 복사, 메모리할당하여 사용하므로 비효율적일 수 있다.
 */
namespace Constants
{
	const double pi(3.141592);
	const double gravity(9.8);
}

namespace Constants2
{
	extern const double pi;
	extern const double gravity;
}
