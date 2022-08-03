#include <iostream>
#include "add.h"
#include "add.h"

/*
 * header의 중복된 구현체 선언으로 인한 컴파일오류를 막기 위해
 * 헤더정의 시 헤더가드 (#pragma once) 를 사용하도록 한다.
 */
int	main(void)
{
	std::cout << add(1,2) << std::endl;
	return (0);
}
