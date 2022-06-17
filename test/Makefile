all: a.out

a.out: a.cpp
#	g++ -I ../../json_struct/include -I ../inc -g a.cpp ../src/groth16/verifier.cpp ../src/groth16/bls12_381/*.cpp
	g++ -I ../../json_struct/include -I ../inc -O2 -s a.cpp ../src/groth16/verifier.cpp ../src/groth16/bls12_381/*.cpp

run: a.out
	./a.out

clean:
	rm -rf a.out
