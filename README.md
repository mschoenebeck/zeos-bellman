# ZEOS Bellman

ZEOS Bellman is a fully EOSIO compatible C++ implementation of 'groth16' verifier of the [bellman](https://github.com/zkcrypto/bellman/) crate used in ZCash Sapling. 

## Installation

No installation necessary.

## Usage

Head into the 'test' folder to run an example of a proof verification.

```bash
cd test
make run
```

The hard-coded strings inside `a.cpp` represent a verifying key `vk`, an actual `proof` as well as corresponding encoded public `inputs` of two different zero knowledge proofs.

To create your own zero knowledge proofs check out the [rustzeos](https://github.com/mschoenebeck/rustzeos) repository and create your own custom circuits as described [here](https://docs.rs/bellman/latest/bellman/). To create the strings of `vk`, `proof` and `inputs` use the `to_json()` function of `librustzeos`. See [test_librustzeos.rs](https://github.com/mschoenebeck/rustzeos/blob/main/testzeos/src/test_librustzeos.rs) for an example.

Note: In a production environment the `inputs` string need to be generated on chain (i.e. by the smart contract and not by the client) for security reasons. Use the `inputs_json()` function of the ZEOS smart contract [header file](https://github.com/mschoenebeck/thezeostoken/blob/e0fbc92168c549d3d22c6ee6b56d456de13b2809/contracts/eos/thezeostoken/zeos.hpp#L182) to pack the public inputs on chain.

## Dependencies

* [json_struct](https://github.com/mschoenebeck/json_struct) EOSIO compatible header-only library to parse json strings to C structs.

## Developer Dependencies

* [zeos.hpp]() ZEOS header-only library for EOSIO smart contracts.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
